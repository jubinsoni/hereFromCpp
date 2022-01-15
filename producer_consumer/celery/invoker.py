import time
from tasks import add,  data_extractor
from celery.result import AsyncResult

#calls add function
result = add.delay(1, 2) # this result = taks_id

while True:
	_result2 = AsyncResult(result.task_id)
	status = _result2.status
	print(status)
	if 'SUCCESS' in status: # checks the status of task
		print('result after 5 sec wait {_result2}'.format(_result2=_result2.get()))
		break
	time.sleep(5)


#calls add function
result = data_extractor.delay() # this result = taks_id

# while True:
# 	_result2 = AsyncResult(result.task_id)
# 	status = _result2.status
# 	print(status)
# 	if 'SUCCESS' in status: # checks the status of task
# 		print('result after 5 sec wait {_result2}'.format(_result2=_result2.get()))
# 		break
# 	time.sleep(5)