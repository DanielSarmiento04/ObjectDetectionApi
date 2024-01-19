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
    python3 


# Set the working directory
WORKDIR /code

# Copy the code source
COPY ./src /code/src
COPY ./test /code/test
COPY CMakeLists.txt /code/CMakeLists.txt
COPY ./utility /code/utility

# Build the project dependencies oatpp
RUN ./utility/install-oatpp-modules.sh

# Build the project
WORKDIR /code/build
RUN cmake ..
RUN make


EXPOSE 8000 8000

ENTRYPOINT ["./api_machine_learning-exe"]
