FROM alpine:3.14


RUN apk update \
  && apk upgrade 

RUN apk add --no-cache \
    clang \
    clang-dev \
    alpine-sdk \
    dpkg \
    cmake \
    ccache 
    
RUN apk update \
  && apk upgrade 

ADD . /code/

WORKDIR /code

# Build the project dependencies oatpp
RUN ./utility/install-oatpp-modules.sh

# build  the project
RUN mkdir -p /code/build \
  && cd /code/build 

WORKDIR /code/build/
RUN cmake ..
RUN make -j4

EXPOSE 8000 8000

ENTRYPOINT ["./api_machine_learning-exe"]
