import threading, cv2
import time


class Stack:
    def __init__(self, stack_size):
        self.items = []
        self.stack_size = stack_size

    def is_empty(self):
        return len(self.items) == 0

    def pop(self):
        return self.items.pop()

    def peek(self):
        if not self.isEmpty():
            return self.items[len(self.items) - 1]

    def size(self):
        return len(self.items)

    def push(self, item):
        if self.size() >= self.stack_size:
            self.items.remove(self.items[0])
        self.items.append(item)

    def clear(self):
        self.items.clear()


def capture_thread(video_path, frame_buffer, lock):
    print("capture_thread start")
    vid = cv2.VideoCapture(video_path)
    print(vid.get(cv2.CAP_PROP_FPS))
    if not vid.isOpened():
        raise IOError("Couldn't open webcam or video")
    while True:
        return_value, frame = vid.read()
        if return_value is not True:
            break
        lock.acquire()
        start_time = time.time()
        print('图像存放时间：', start_time)
        frame_buffer.push([frame, start_time])
        print('存放后列表中有图像的张数：', frame_buffer.size())
        lock.release()
        cv2.waitKey(25)


def play_thread(frame_buffer, lock):
    print("detect_thread start")
    print("detect_thread frame_buffer size is", frame_buffer.size())

    while True:
        if frame_buffer.size() >= 1:
            lock.acquire()
            frame_list = frame_buffer.pop()
            frame = frame_list[0]
            end_time = time.time()
            frame_buffer.clear()
            print('图像取出时间：', end_time)
            print('取出后列表中有图像的张数：', frame_buffer.size())
            print('每张图像显示时间：', end_time - frame_list[1])
            lock.release()
            # TODO 算法
            cv2.imshow("result", frame)
            if cv2.waitKey(1) & 0xFF == ord('q'):
                break


# path = 'rtsp://admin:abcd1234@192.168.1.64'
path = 'rtsp://192.168.1.152/chn0'
# path=0
frame_buffer = Stack(3)
lock = threading.RLock()
t1 = threading.Thread(target=capture_thread, args=(path, frame_buffer, lock))
t1.start()
t2 = threading.Thread(target=play_thread, args=(frame_buffer, lock))
t2.start()