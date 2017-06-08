FROM alpine:3.6

MAINTAINER Parameswaran Selvam <parselva@in.ibm.com> (@Param-S)

RUN apk --update add --no-cache git make binutils musl-dev gcc g++ libunwind-dev perl

WORKDIR /src

RUN git clone https://github.com/Param-S/omr.git \
    && cd omr \ 
    && git fetch \
    && muslCommit=$(git log remotes/origin/muslcompile | head | grep commit | awk '{print $2}') \
    && git cherry-pick --no-commit $muslCommit
