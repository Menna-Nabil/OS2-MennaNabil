
FROM gcc:13

WORKDIR /application

COPY MennaNabil.cpp .

RUN g++ MennaNabil.cpp -o MennaNabil

CMD ["./MennaNabil"]
