FROM geant4/geant4:latest-aarch64

# update
RUN sh -c "yum update -y && yum install epel-release -y"

# Install dependencies
RUN sh -c "yum install -y git make cmake gcc-c++ gcc binutils libX11-devel libXpm-devel libXft-devel libXext-devel python3.11 openssl-devel"

# build ROOT
RUN sh -c "git clone --branch latest-stable --depth=1 https://github.com/root-project/root.git /root/src && mkdir -p /root/install /root/build"
RUN sh -c "cd /root/build && cmake -DCMAKE_CXX_STANDARD=17 -DCMAKE_INSTALL_PREFIX=/root/install /root/src"
RUN sh -c "cd /root/build && cmake --build . --target install -j2"
RUN sh -c "echo 'source /root/install/bin/thisroot.sh' >> /root/.bashrc"