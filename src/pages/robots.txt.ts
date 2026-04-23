import type { APIRoute } from 'astro';

export const GET: APIRoute = ({ site }) => {
  const base = site?.toString() ?? 'https://example.com/';

  return new Response(`User-agent: *
Allow: /
Sitemap: ${new URL('sitemap-index.xml', base).toString()}
`);
};
