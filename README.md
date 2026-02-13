# athabasca-university-docs
Contains projects written during Comp Sci & Mathematics study.

![oreily image](COMP200/images/cs200-oreily.png)

## Come watch me lose my mind


### COMP200

> Deployed at: https://comp200-athabasca-university-docs.readthedocs.io/en/latest/index.html

If you've found this repo, you might be studying CS and Mathematics with me at AU. I’ve taken a somewhat unconventional path. I got a job working in computing before studying it. I automate solutions every week, build websites, create plugins for the Atlassian marketplace, and write a lot of developer documentation for APIs. 

I know how to write something that works, but as things became more complex, I realized how little I truly knew. I never understood *why* it worked.

So here I am, figuring out why my bug-driven, brute-force development works—and why it doesn’t.

The project includes documentation and project files.


### COMP266 folder structure
Project  contains 16 directories, 55 files.

> This project was built during my studies at Athabasca University, and was built to be compatible with mobile, web, and small monitors.

When you open the site, index.html is served up first with a welcome screen, which serves as a way to hydrate resources in advance. After load, you'll land on ../welcome/index.html. The loader only gets accessed on the initial site visit.


+ assets contains: project assets, including sass, css, icons, and images.

+ docs contains: license, and README. For supporting tools docs, check the site and go to the affiliated GH link.

+ home contains: main root of site. Contains .html files for about, tools, and welcome -- the main three navigation options of the site. 

        .
        ├── assets
        │   ├── icons
        │   │   ├── amd-icon.png
        │   │   ├── apple-touch-icon.png
        │   │   ├── bandai-icon.png
        │   │   ├── caf-icon.png
        │   │   ├── de-icon.jpg
        │   │   ├── factory-icon.png
        │   │   ├── framos-icon.png
        │   │   ├── gd-icon.png
        │   │   ├── github-icon.png
        │   │   ├── gnu-public-license-icon.png
        │   │   ├── intel-icon.jpg
        │   │   ├── linkedin-icon.png
        │   │   ├── nintendo-icon.png
        │   │   ├── nvidia-logo.png
        │   │   ├── raw-thrills-icon.png
        │   │   ├── reddit-icon.png
        │   │   └── tssa-icon.jpg
        │   ├── images
        │   │   ├── image-skull1-loader.svg
        │   │   ├── image-skull2-loader.svg
        │   │   ├── image-skull3-loader.svg
        │   │   ├── og-image.png
        │   │   ├── tool-dependencies-2.gif
        │   │   ├── tool-postproc-4.gif
        │   │   ├── tool-preproc-3.gif
        │   │   └── tool-problem-1.gif
        │   ├── js
        │   │   ├── app.js
        │   │   ├── github-api.js
        │   │   ├── loader.js
        │   │   ├── news-api.js
        │   │   ├── particles.js
        │   │   ├── popup.js
        │   │   ├── responsiveScript.js
        │   │   ├── testimonials.js
        │   │   └── validation.js
        │   └── sass
        │       ├── main.scss
        │       └── modules
        │           ├── common
        │           │   └── reset.scss
        │           ├── layouts
        │           │   ├── body.scss
        │           │   ├── email.scss
        │           │   ├── footer.scss
        │           │   ├── headings.scss
        │           │   ├── navbar.scss
        │           │   ├── para.scss
        │           │   ├── popup.scss
        │           │   └── table.scss
        │           └── pages
        │               ├── index.scss
        │               └── landing.scss
        ├── css
        │   ├── styles.css
        │   └── styles.css.map
        ├── docs
        │   ├── LICENSE.txt
        │   └── README.md
        ├── home
        │   ├── about
        │   │   └── index.html
        │   ├── tools
        │   │   └── index.html
        │   └── welcome
        │       └── index.html
        ├── index.html
        └── package.json
