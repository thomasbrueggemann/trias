FROM ubuntu:16.04

LABEL version="1.0"
LABEL description="Convert images to computer generated art using delaunay triangulation."
LABEL maintainer="mail@thomasbrueggemann.com"

# INSTALL DEPENDENCIES
RUN add-apt-repository ppa:jonathonf/gcc-7.1
RUN apt-get update && apt-get -y install gcc-7 g++-7 libmagick++-dev