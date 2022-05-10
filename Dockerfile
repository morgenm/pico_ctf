from kalilinux/kali-rolling

RUN apt update
RUN apt install -y curl gdb git
WORKDIR /root/pwndbg
RUN git clone "https://github.com/pwndbg/pwndbg"
WORKDIR /root/pwndbg/pwndbg
RUN ./setup.sh
