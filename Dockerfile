FROM alpine:3.14


RUN apk update \
  && apk upgrade 

RUN apk add --no-cache \
    clang \
    clang-dev \
    alpine-sdk \
    dpkg \
    cmake \
    ccache \
    wget \
    ffmpeg
    
RUN apk update \
  && apk upgrade 

ADD . /code/

WORKDIR /code

# Build the project dependencies oatpp
RUN ./utility/install-oatpp-modules.sh


RUN apk add --no-cache \
      libgtk3.0-dev \
      libpng-dev \
      libjpeg-dev \ 
      libopenexr-dev \
      libtiff-dev \
      libwebp-dev
# Build OpenCv dependencies
# RUN ./utility/install-opencv.sh


# # build  the project
# RUN mkdir -p /code/build \
#   && cd /code/build 

# WORKDIR /code/build/
# RUN cmake ..
# RUN make -j4

# EXPOSE 8000 8000

# ENTRYPOINT ["./api_machine_learning-exe"]
