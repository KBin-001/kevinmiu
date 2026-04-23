export type Category = {
  slug: string;
  name: string;
  description: string;
  order: number;
};

export const categories: Category[] = [
  {
    slug: 'software',
    name: '软件资源',
    description: '桌面软件、移动应用、效率工具和替代方案。',
    order: 1
  },
  {
    slug: 'dev-tools',
    name: '开发工具',
    description: '面向开发者和嵌入式工程师的 IDE、命令行和调试工具。',
    order: 2
  },
  {
    slug: 'tutorials',
    name: '教程文章',
    description: '可长期检索的安装、配置、使用和避坑指南。',
    order: 3
  },
  {
    slug: 'collections',
    name: '资源合集',
    description: '按场景整理的一站式资源清单。',
    order: 4
  },
  {
    slug: 'websites',
    name: '网站导航',
    description: '值得收藏的在线服务、资源站点和资料入口。',
    order: 5
  }
];

export function getCategory(slug: string) {
  return categories.find((category) => category.slug === slug);
}

export function getCategoryName(slug: string) {
  return getCategory(slug)?.name ?? slug;
}
