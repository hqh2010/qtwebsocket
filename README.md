# 说明

this is a demo for qt websocket.

## 使用方法

```
sudo apt install libqt5websockets5-dev

mkdir build

cd build

make -j4

./echoclient
```

运行结果

```
uos@uos:~/Desktop/websocket/build$ ./echoclient
begin to listen...
WebSocket server: QUrl("ws://10.20.54.2:10100/websocket/watcher/17236529-5149-9572-71f7-8512ad5e2f21")
connected success
WebSocket connected
Message received: "watchID not found"
EchoClient close
```

使用curl命令结果结果如下：

uos@uos:~/8.linglong/GitPrj/debug/linglong/build$ curl  --header "Connection: Upgrade" \

> --header "Upgrade: websocket"
> --header "Sec-WebSocket-Key: 123456=="
> --header "Sec-WebSocket-Version: 13"
> http://10.20.54.2:10100/websocket/watcher/17236529-5149-9572-71f7-8512ad5e2f21
> �watchID not found

## 参考

- [qt websocket官方demo](https://code.qt.io/cgit/qt/qtwebsockets.git/tree/examples/websockets?h=6.4)
- [linux curl 测试 websocket 服务](https://blog.51cto.com/niuben/3028513)
