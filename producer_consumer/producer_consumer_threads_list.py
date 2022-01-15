# Do run this program so that you understand the flow
import threading

import time
import random

queue = []
MAX_ITEMS = 10

condition = threading.Condition()

class ProducerThread(threading.Thread):

    def run(self):

        numbers = range(5)
        global queue

        while True:
            condition.acquire() # acquire lock
            if len(queue) == MAX_ITEMS:
                print("Queue is full, producer is waiting")
                condition.wait() # if condition fullfills then release lock for consumer to consume message and wait for notify from consumer
                print("Space in queue, Consumer notified producer")
            number = random.choice(numbers) # random number is generated between 0 and 5
            queue.append(number) # producer adds number to queue
            print("Produced {}".format(number))
            condition.notify() # notify consumer that we added a new elemnet to queue
            condition.release() # release lock
            time.sleep(random.random())

class ConsumerThread(threading.Thread):

    def run(self):
        global queue

        while True:
            condition.acquire() # acquire lock
            if len(queue) == 0:
                print("Noting in queue, consumer waiting")
                condition.wait()# if condition fullfills then release lock for producer to add message and wait for notify from producer
                print("Producer added something to queue, Producer notify consumer")
            number = queue.pop(0)# consumer removes the number from queue
            print("Consumed {}".format(number))
            condition.notify() # notify producer that we consumed a number from queue
            condition.release() # release lock
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