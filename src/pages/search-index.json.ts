import { getCollection } from 'astro:content';
import { getEntryRouteSlug } from '@/lib/content';
import { getCategoryName } from '@/lib/taxonomy';

const stripMarkdown = (value = '') =>
  value
    .replace(/```[\s\S]*?```/g, ' ')
    .replace(/`([^`]+)`/g, '$1')
    .replace(/!\[[^\]]*\]\([^)]+\)/g, ' ')
    .replace(/\[([^\]]+)\]\([^)]+\)/g, '$1')
    .replace(/[#>*_\-~|]/g, ' ')
    .replace(/\s+/g, ' ')
    .trim();

const toDate = (date: Date) =>
  new Intl.DateTimeFormat('zh-CN', {
    year: 'numeric',
    month: '2-digit',
    day: '2-digit'
  }).format(date);

const getFileName = (file: string) => {
  const name = file.split('/').filter(Boolean).pop() ?? file;
  try {
    return decodeURIComponent(name);
  } catch {
    return name;
  }
};

export async function GET() {
  const [posts, resources] = await Promise.all([
    getCollection('posts', ({ data }) => !data.draft),
    getCollection('resources', ({ data }) => !data.draft)
  ]);

  const items = [
    ...posts.map((entry) => {
      const isProtected = Boolean(entry.data.accessProtected);
      const attachmentText = (entry.data.attachments ?? []).map(getFileName).join(' ');
      const body = isProtected ? '' : `${stripMarkdown(entry.body ?? '')} ${attachmentText}`.trim();

      return {
        id: entry.id,
        kind: '文章',
        title: entry.data.title,
        description: entry.data.description,
        category: entry.data.category,
        categoryName: getCategoryName(entry.data.category),
        tags: entry.data.tags,
        url: `/posts/${getEntryRouteSlug(entry)}/`,
        updatedAt: toDate(entry.data.updatedAt),
        protected: isProtected,
        body
      };
    }),
    ...resources.map((entry) => {
      const isProtected = Boolean(entry.data.accessProtected);
      const attachmentText = (entry.data.attachments ?? []).map(getFileName).join(' ');
      const body = isProtected ? '' : `${stripMarkdown(entry.body ?? '')} ${attachmentText}`.trim();

      return {
        id: entry.id,
        kind: '资源',
        title: entry.data.title,
        description: entry.data.description,
        category: entry.data.category,
        categoryName: getCategoryName(entry.data.category),
        tags: entry.data.tags,
        url: `/resources/${getEntryRouteSlug(entry)}/`,
        updatedAt: toDate(entry.data.updatedAt),
        protected: isProtected,
        body
      };
    })
  ].sort((a, b) => b.updatedAt.localeCompare(a.updatedAt));

  return new Response(JSON.stringify({ items }), {
    headers: {
      'Content-Type': 'application/json; charset=utf-8',
      'Cache-Control': 'public, max-age=300'
    }
  });
}
