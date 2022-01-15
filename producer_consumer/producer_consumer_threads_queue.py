# Do run this program so that you understand the flow
import threading

import time
import random
import queue

_queue = queue.Queue(10)

condition = threading.Condition()

class ProducerThread(threading.Thread):

    def run(self):

        numbers = range(5)
        global _queue

        while True:
            number = random.choice(numbers) # random number is generated between 0 and 5
            _queue.put(number) # producer adds number to queue
            print("Produced {}".format(number))
            time.sleep(random.random())

class ConsumerThread(threading.Thread):

    def run(self):
        global _queue

        while True:
            number = _queue.get()# consumer removes the number from queue
            _queue.task_done()# tells queue ds that we are done extracting the number
            print("Consumed {}".format(number))
            time.sleep(random.random())

producer = ProducerThread()
producer.daemon = True
producer.start()

consumer = ConsumerThread()
consumer.daemon = True
consumer.start()

# thread.daemon = True to run in background
# ps -ef | grep producer*
# pkill -9 -f producer*
# add below while when thread.daemon = True to debug

while True:
    time.sleep(1)