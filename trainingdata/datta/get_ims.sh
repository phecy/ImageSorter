#!/bin/bash
cat ids.txt | while read id; do
    url=http://www.dpchallenge.com/image.php?IMAGE_ID=$id
    wget $(wget -O- $url |
    sed -n 's/.*img src=\"\(http[^"]*Copyrighted_Image_Reuse_Prohibited[^"]*.jpg\).*/\1/p') -O images/$id.jpg;
done
