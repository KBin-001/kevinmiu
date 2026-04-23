# kevinmiu 内容后台说明

kevinmiu 使用 Pages CMS 作为轻量后台。它不会引入数据库，也不需要维护服务器；后台会直接编辑 GitHub 仓库里的 Markdown 文件。

## 后台入口

打开：

```txt
https://app.pagescms.org/
```

然后用 GitHub 登录，选择当前网站仓库。

## 内容类型

文章：

```txt
src/content/posts
```

适合教程、资讯、合集、说明类内容。

资源：

```txt
src/content/resources
```

适合软件、网站、AI 工具、福利活动、开发工具等条目。

## 发布流程

1. 在 Pages CMS 里新建文章或资源。
2. 填写标题、slug、分类、标签、发布时间、更新时间。
3. 正文用 Markdown 编辑。
4. 保存后 Pages CMS 会提交到 GitHub。
5. GitHub 更新后 Cloudflare Pages 自动构建并上线。

## 字段说明

`slug` 是 URL 的一部分，只用英文小写、数字和短横线。

```txt
good: windows-tools
bad: Windows 工具
```

`draft` 控制是否发布：

```txt
true  = 草稿，不上线
false = 正式发布
```

`featured` 控制是否进入首页推荐：

```txt
true  = 首页推荐
false = 普通内容
```

## 分类 slug

```txt
benefits    资源福利
software    软件工具
dev-tools   开发工具
ai-tools    AI 工具
websites    网站导航
tutorials   教程文章
news        资讯动态
```

## 本地兜底方式

如果 Pages CMS 暂时不可用，也可以直接编辑 Markdown 文件，然后运行：

```bash
npm run build
git add .
git commit -m "content: update"
git push
```
