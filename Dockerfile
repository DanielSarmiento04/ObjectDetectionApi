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

# Set the working directory
WORKDIR /code

# Copy the code source
COPY . /code/

# Build the project dependencies oatpp
RUN ./utility/install-oatpp-modules.sh

# Build the project
RUN mkdir -p /code/build
WORKDIR /code/build
RUN ls .

RUN cmake ..
RUN make


EXPOSE 8000 8000

ENTRYPOINT ["./api_machine_learning-exe"]
