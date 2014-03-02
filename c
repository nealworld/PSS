from lxml import html
import requests
import time
import easygui
from time import gmtime, strftime
import datetime
def getLastPrice():
	while(True):
		try:
			page = requests.get('https://vip.btcchina.com/')
			tree = html.fromstring(page.text)
		except:
			print("a exception happened!")
		else:	
			price = tree.xpath('//span[@id="last"]/text()')
			return float(price[0].replace(',',''))

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
