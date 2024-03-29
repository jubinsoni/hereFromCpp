# cd ~/Desktop/coding_ds_algo/hereFromCpp/producer_consumer
# python3 -m sqs.sqs-consumer

import time
import json
import boto3

from .config import QUEUE_URL, ACCESS_KEY, SECRET_KEY

sqs = boto3.client('sqs', region_name='ap-south-1', aws_access_key_id=ACCESS_KEY, aws_secret_access_key=SECRET_KEY)


#if __name__ == '__main__':
def start_consumer():
    print('STARTING WORKER listening on {}'.format(QUEUE_URL))
    while 1:
        response = sqs.receive_message(
            QueueUrl=QUEUE_URL,
            AttributeNames=['All'],
            MessageAttributeNames=[
                'string',
            ],
            MaxNumberOfMessages=1,
            WaitTimeSeconds=10,
        )
        messages = response.get('Messages', [])
        for message in messages:
            try:
                print('Message Body > ', message.get('Body'))
                body = json.loads(message.get('Body'))
                if not body.get('jobId', None):
                    print('Job Id not provided!')
                    sqs.delete_message(QueueUrl=QUEUE_URL, ReceiptHandle=message.get('ReceiptHandle'))
                    print('Received and deleted message: {}'.format(message))
                else:
                    job_id = body['jobId']
                    print('Running Job Id {}'.format(job_id))
                    sqs.delete_message(QueueUrl=QUEUE_URL, ReceiptHandle=message.get('ReceiptHandle'))
                    print('Received and deleted message: {}'.format(message))
            except Exception as e:
                print('Exception in worker > ', e)
                sqs.delete_message(QueueUrl=QUEUE_URL, ReceiptHandle=message.get('ReceiptHandle'))

    time.sleep(10)

start_consumer()
print('WORKER STOPPED')
