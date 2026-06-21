
FROM ubuntu:24.04


RUN apt update

RUN apt install -y libsqlite3-dev


COPY . /app


WORKDIR /app/build


CMD ["./rrserver"]

