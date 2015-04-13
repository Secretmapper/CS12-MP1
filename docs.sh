#!/bin/bash
echo -e "Publishing doxygen. \n"

doxygen

cd html
git add -A
git commit -m "[GH-PAGES] [DOC] Updated doxygen script-push to gh-pages"
git push origin gh-pages

echo -e "Published doxygen to gh-pages. \n"
