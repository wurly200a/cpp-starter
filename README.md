
## Prepare using docker container

```
docker run --rm -it --user ubuntu -v ${PWD}:/workspaces/cpp-starter -w /workspaces/cpp-starter ghcr.io/wurly200a/builder-linux:latest
```

## Build

```
cmake -B build -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
cmake --build build -j
```

## Run

```
./build/cpp-starter 
```
