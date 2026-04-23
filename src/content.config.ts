import { defineCollection } from 'astro:content';
import { glob } from 'astro/loaders';
import { z } from 'astro/zod';

const commonSchema = z.object({
  title: z.string(),
  slug: z.string(),
  description: z.string(),
  category: z.string(),
  tags: z.array(z.string()).default([]),
  publishedAt: z.coerce.date(),
  updatedAt: z.coerce.date(),
  featured: z.boolean().default(false),
  draft: z.boolean().default(false),
  cover: z.string().optional()
});

const posts = defineCollection({
  loader: glob({ pattern: '**/*.{md,mdx}', base: './src/content/posts' }),
  schema: commonSchema
});

const resources = defineCollection({
  loader: glob({ pattern: '**/*.{md,mdx}', base: './src/content/resources' }),
  schema: commonSchema.extend({
    url: z.url().optional(),
    pricing: z.enum(['free', 'freemium', 'paid', 'open-source']).optional(),
    platforms: z.array(z.string()).default([]),
    rating: z.number().min(1).max(5).optional()
  })
});

export const collections = { posts, resources };
