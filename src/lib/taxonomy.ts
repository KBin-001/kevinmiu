export type Category = {
  slug: string;
  name: string;
  description: string;
  order: number;
};

export const categories: Category[] = [
  {
    slug: 'benefits',
    name: '资源福利',
    description: '限免活动、免费资源、会员福利、优惠信息和实用领取入口。',
    order: 1
  },
  {
    slug: 'software',
    name: '软件工具',
    description: 'Windows、macOS、Android、iOS 上值得长期使用的软件和效率工具。',
    order: 2
  },
  {
    slug: 'dev-tools',
    name: '开发工具',
    description: 'IDE、命令行、调试、部署、API、数据库和工程效率工具。',
    order: 3
  },
  {
    slug: 'ai-tools',
    name: 'AI 工具',
    description: 'AI 写作、绘图、编程助手、模型平台和提示词工具。',
    order: 4
  },
  {
    slug: 'websites',
    name: '网站导航',
    description: '值得收藏的在线服务、资源站点、学习资料和工具入口。',
    order: 5
  },
  {
    slug: 'tutorials',
    name: '教程文章',
    description: '安装配置、使用指南、避坑记录、资源合集和长期教程。',
    order: 6
  },
  {
    slug: 'news',
    name: '资讯动态',
    description: '软件更新、开发者新闻、AI 动态、活动消息和实用资讯。',
    order: 7
  }
];

export function getCategory(slug: string) {
  return categories.find((category) => category.slug === slug);
}

export function getCategoryName(slug: string) {
  return getCategory(slug)?.name ?? slug;
}
