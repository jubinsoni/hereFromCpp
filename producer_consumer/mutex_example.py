import threading

counter_buffer = 0
counter_lock = threading.Lock()

COUNTER_MAX = 1000000

def consumer1_counter():
    global counter_buffer
    for i in range(COUNTER_MAX):
        counter_lock.acquire()
        counter_buffer = counter_buffer + 1
        counter_lock.release()

def consumer2_counter():
    global counter_buffer
    for i in range(COUNTER_MAX):
        counter_lock.acquire()
        counter_buffer = counter_buffer + 1
        counter_lock.release()


t1 = threading.Thread(target=consumer1_counter)
t2 = threading.Thread(target=consumer2_counter)

t1.start()
t2.start()

t1.join()
t2.join()

print("counter_buffer 1st run => ",counter_buffer) # should be 2000000 as each thread tries to increase it till 1000000
#prints 2000000

import threading

counter_buffer = 0
counter_lock = threading.Lock()

COUNTER_MAX = 1000000

def consumer1_counter():
    global counter_buffer
    for i in range(COUNTER_MAX):
        #counter_lock.acquire()
        counter_buffer = counter_buffer + 1
        #counter_lock.release()

def consumer2_counter():
    global counter_buffer
    for i in range(COUNTER_MAX):
        #counter_lock.acquire()
        counter_buffer = counter_buffer + 1
        #counter_lock.release()


t1 = threading.Thread(target=consumer1_counter)
t2 = threading.Thread(target=consumer2_counter)

t1.start()
t2.start()

t1.join()
t2.join()

print("counter_buffer 2nd run => ",counter_buffer) # should be 2000000 as each thread tries to increase it till 1000000
# prints 1387728