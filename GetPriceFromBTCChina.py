from lxml import html
import requests
import time
import easygui
from time import gmtime, strftime
import datetime
def getLastPrice():
	while(True):
		try:
			page = requests.get('https://data.btcchina.com/data/ticker')
		except:
			print("a exception happened!")
		else:	
			return float((page.text.split(',')[4]).split(':')[1].split('"')[1])

def start():
	while(True):
		price = getLastPrice()
		if(price < 2500.0):
			easygui.msgbox("The price is below 2500.0!", title="BTC price warning")
		else:
			now = datetime.datetime.now()
			print(now.strftime("%Y-%m-%d %H:%M") +' price is ' + str(price))
			time.sleep(10)

start()
