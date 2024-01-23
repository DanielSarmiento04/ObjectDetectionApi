FROM alpine:3.14

RUN apk update \
  && apk upgrade 

# Add Edge repos
RUN echo -e "\n\
@edgemain http://nl.alpinelinux.org/alpine/edge/main\n\
@edgecomm http://nl.alpinelinux.org/alpine/edge/community\n\
@edgetest http://nl.alpinelinux.org/alpine/edge/testing"\
>> /etc/apk/repositories

RUN apk add --no-cache \
  bash \
  build-base \
  ca-certificates \
  clang-dev \
  clang \
  cmake \
  coreutils \
  curl \ 
  freetype-dev \
  ffmpeg-dev \
  ffmpeg-libs \
  gcc \
  g++ \
  git \
  gettext \
  lcms2-dev \
  libavc1394-dev \
  libc-dev \
  libffi-dev \
  libjpeg-turbo-dev \
  libpng-dev \
  libressl-dev \
  libtbb@edgetest \
  libtbb-dev@edgetest \
  libwebp-dev \
  linux-headers \
  make \
  musl \
  openblas@edgecomm \
  openblas-dev@edgecomm \
  openjpeg-dev \
  openssl \
  tiff-dev \
  unzip \
  zlib-dev
    
RUN apk update \
  && apk upgrade 

ADD . /code/

RUN rm -rf /tmp
RUN mkdir /tmp && cd /tmp && \
  wget -O opencv.zip https://github.com/opencv/opencv/archive/4.8.1.zip && \
  wget -O opencv_contrib.zip https://github.com/opencv/opencv_contrib/archive/4.8.1.zip

RUN unzip /tmp/opencv.zip -d /tmp && \
  unzip /tmp/opencv_contrib.zip -d /tmp

RUN rm /tmp/opencv.zip && rm /tmp/opencv_contrib.zip

WORKDIR /tmp/opencv-4.8.1

RUN mkdir build && cd build && \
  cmake -D CMAKE_BUILD_TYPE=RELEASE \
  -D CMAKE_INSTALL_PREFIX=/usr/local \
  -D OPENCV_EXTRA_MODULES_PATH=/tmp/opencv_contrib-4.8.1/modules \
  -D CMAKE_C_COMPILER=/usr/bin/clang \
  -D CMAKE_CXX_COMPILER=/usr/bin/clang++ \
  -D CMAKE_INSTALL_PREFIX=/usr/local \
  -D INSTALL_PYTHON_EXAMPLES=OFF \
  -D INSTALL_C_EXAMPLES=OFF \
  -D WITH_FFMPEG=ON \
  -D WITH_TBB=ON \
  ..

# WORKDIR /code
# Build the project dependencies oatpp
# RUN ./utility/install-oatpp-modules.sh

# Build OpenCv dependencies



# # build  the project
# RUN mkdir -p /code/build \
#   && cd /code/build 

# WORKDIR /code/build/
# RUN cmake ..
# RUN make -j4

# EXPOSE 8000 8000

# ENTRYPOINT ["./api_machine_learning-exe"]
