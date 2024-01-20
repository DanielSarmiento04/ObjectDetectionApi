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

# Build the project
RUN cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_C_COMPILER=clang . \
    && make 
    # && make install

EXPOSE 8000 8000

ENTRYPOINT ["./api_machine_learning-exe"]
