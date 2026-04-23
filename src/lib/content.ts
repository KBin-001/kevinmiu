import { getCollection, type CollectionEntry } from 'astro:content';

export type ContentKind = 'post' | 'resource';

export type ContentItem = {
  id: string;
  kind: ContentKind;
  title: string;
  slug: string;
  description: string;
  category: string;
  tags: string[];
  publishedAt: Date;
  updatedAt: Date;
  featured: boolean;
  url: string;
  sourceUrl?: string;
};

export type PostEntry = CollectionEntry<'posts'>;
export type ResourceEntry = CollectionEntry<'resources'>;

export function toContentItem(entry: PostEntry | ResourceEntry, kind: ContentKind): ContentItem {
  return {
    id: entry.id,
    kind,
    title: entry.data.title,
    slug: entry.data.slug,
    description: entry.data.description,
    category: entry.data.category,
    tags: entry.data.tags,
    publishedAt: entry.data.publishedAt,
    updatedAt: entry.data.updatedAt,
    featured: entry.data.featured,
    url: kind === 'post' ? `/posts/${entry.data.slug}/` : `/resources/${entry.data.slug}/`,
    sourceUrl: kind === 'resource' ? (entry as ResourceEntry).data.url : undefined
  };
}

export async function getPublishedPosts() {
  return getCollection('posts', ({ data }) => !data.draft);
}

export async function getPublishedResources() {
  return getCollection('resources', ({ data }) => !data.draft);
}

export async function getAllContentItems() {
  const [posts, resources] = await Promise.all([getPublishedPosts(), getPublishedResources()]);
  return [
    ...posts.map((entry) => toContentItem(entry, 'post')),
    ...resources.map((entry) => toContentItem(entry, 'resource'))
  ].sort((a, b) => b.updatedAt.getTime() - a.updatedAt.getTime());
}

export function getAllTags(items: ContentItem[]) {
  return [...new Set(items.flatMap((item) => item.tags))].sort((a, b) => a.localeCompare(b, 'zh-CN'));
}

export function formatDate(date: Date) {
  return new Intl.DateTimeFormat('zh-CN', {
    year: 'numeric',
    month: '2-digit',
    day: '2-digit'
  }).format(date);
}
