FROM alpine:3.14

RUN apk update

# Install packages
RUN apk add --no-cache \
    bash \
    curl \
    git \
    jq \
    openssh-client \
    wget \
    zip 
RUN apk add build-base cmake linux-headers
RUN apk add python3-dev py3-numpy
RUN apk add opencv opencv-dev

ADD . /code/

WORKDIR /code

# Build the project dependencies oatpp
RUN ./utility/install-oatpp-modules.sh

# build  the project
RUN mkdir -p /code/build \
  && cd /code/build 

WORKDIR /code/build/
RUN cmake -DOpenCV_DIR=/usr/lib/cmake/opencv4 ..
RUN make -j4

EXPOSE 8000 8000

ENTRYPOINT ["./api_machine_learning-exe"]
