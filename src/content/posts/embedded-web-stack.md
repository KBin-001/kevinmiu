---
title: "嵌入式工程师做个人网站的技术栈取舍"
slug: "embedded-web-stack"
description: "从学习成本、部署成本和长期维护角度，说明为什么个人内容站适合先从静态生成开始。"
category: "tutorials"
tags: ["独立开发", "Astro", "技术选型"]
publishedAt: "2026-04-23"
updatedAt: "2026-04-23"
featured: false
draft: false
---

嵌入式工程师通常熟悉工程构建、版本管理和 Linux 环境，但不一定熟悉前端状态管理、服务端框架和数据库权限。

个人网站第一版应该避免一开始就引入太多运行时服务。静态生成的内容站更像一个可编译工程：修改 Markdown，执行构建，发布产物。

## 建议顺序

先做内容模型和页面结构，再做搜索和 SEO，最后再考虑用户系统、评论和投稿。
