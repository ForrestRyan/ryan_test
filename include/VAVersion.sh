#!/bin/sh
echo "current dir: $(pwd)"
commit_ts=`git log -1 --format="%ct"`
commit_time=`date -d@$commit_ts +"%Y-%m-%d %H:%M:%S"`
current_time=`date +"%Y-%m-%d %H:%M:%S"`
git_version=`git log -1 --format="%h"`
cur_dir=$(pwd)/../crf_based/include
sed  s/MYVERSION/"RELEASE_VERSION: $git_version, commit: $commit_time, build: $current_time"/g $cur_dir/VAVersion.txt > $cur_dir/VAVersion.h