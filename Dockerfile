FROM ubuntu:20.04

RUN apt-get update \
      && apt-get install -y \
          software-properties-common \
          wget \
      && add-apt-repository -y ppa:ubuntu-toolchain-r/test \
      && apt-get update \
      && apt-get install -y \
          make \
          git \
          curl \
          vim \
          vim-gnome \
      && apt-get install -y cmake=3.5.1-1ubuntu3 \
      && apt-get install -y \
          gcc-4.9 g++-4.9 gcc-4.9-base \
          gcc-4.8 g++-4.8 gcc-4.8-base \
          gcc-4.7 g++-4.7 gcc-4.7-base \
          gcc-4.6 g++-4.6 gcc-4.6-base \
      && update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-4.9 100 \
      && update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-4.9 100

ADD . /code/

WORKDIR /code

# Build the project dependencies oatpp
RUN ./utility/install-oatpp-modules.sh

# Build the project
RUN cmake . \
    && make 
    # && make install

EXPOSE 8000 8000

ENTRYPOINT ["./api_machine_learning-exe"]
