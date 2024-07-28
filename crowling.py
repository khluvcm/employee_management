import requests
import bs4


cookies = {
    'WMONID': 'gVHd10PYRiH',
    'daepyoSidoCd': '30',
    'daepyoSiguCd': '170',
    'realVowel': '35207_45207',
    'realJiwonNm': '%BC%AD%BF%EF%C1%DF%BE%D3%C1%F6%B9%E6%B9%FD%BF%F8',
    'rd1Cd': '30',
    'rd2Cd': '',
    'JSESSIONID': 'Fca4qYc6g0dTHO03585e9ohy16eQWaCdnusGbgaAdcsUvm6AzKmMDrMHbFVlrD1Q.amV1c19kb21haW4vYWlzMQ==',
    'locIdx': '202301300014011',
    'toMul': '%B4%EB%C0%FC%C1%F6%B9%E6%B9%FD%BF%F8%2C20230130001401%2C1%2C20240807%2CB%5E',
}



headers = {
    'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7',
    'Accept-Language': 'en-US,en;q=0.9,ko;q=0.8',
    'Cache-Control': 'max-age=0',
    'Connection': 'keep-alive',
    'Content-Type': 'application/x-www-form-urlencoded',
    # 'Cookie': 'WMONID=gVHd10PYRiH; daepyoSidoCd=30; daepyoSiguCd=170; realVowel=35207_45207; realJiwonNm=%BC%AD%BF%EF%C1%DF%BE%D3%C1%F6%B9%E6%B9%FD%BF%F8; rd1Cd=30; rd2Cd=; JSESSIONID=Fca4qYc6g0dTHO03585e9ohy16eQWaCdnusGbgaAdcsUvm6AzKmMDrMHbFVlrD1Q.amV1c19kb21haW4vYWlzMQ==; locIdx=202301300014011; toMul=%B4%EB%C0%FC%C1%F6%B9%E6%B9%FD%BF%F8%2C20230130001401%2C1%2C20240807%2CB%5E',
    'Origin': 'https://www.courtauction.go.kr',
    'Referer': 'https://www.courtauction.go.kr/InitMulSrch.laf',
    'Sec-Fetch-Dest': 'frame',
    'Sec-Fetch-Mode': 'navigate',
    'Sec-Fetch-Site': 'same-origin',
    'Sec-Fetch-User': '?1',
    'Upgrade-Insecure-Requests': '1',
    'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/127.0.0.0 Safari/537.36',
    'sec-ch-ua': '"Not)A;Brand";v="99", "Google Chrome";v="127", "Chromium";v="127"',
    'sec-ch-ua-mobile': '?0',
    'sec-ch-ua-platform': '"Linux"',
}



data = 'bubwLocGubun=2&jiwonNm=%BC%AD%BF%EF%C1%DF%BE%D3%C1%F6%B9%E6%B9%FD%BF%F8&jpDeptCd=000000&daepyoSidoCd=30&daepyoSiguCd=170&daepyoDongCd=&notifyLoc=on&rd1Cd=30&rd2Cd=&realVowel=35207_45207&rd3Rd4Cd=&notifyRealRoad=on&saYear=2024&saSer=&ipchalGbncd=000331&termStartDt=2024.07.28&termEndDt=2024.08.11&lclsUtilCd=&mclsUtilCd=&sclsUtilCd=&gamEvalAmtGuganMin=&gamEvalAmtGuganMax=&notifyMinMgakPrcMin=&notifyMinMgakPrcMax=&areaGuganMin=&areaGuganMax=&yuchalCntGuganMin=&yuchalCntGuganMax=&notifyMinMgakPrcRateMin=&notifyMinMgakPrcRateMax=&srchJogKindcd=&mvRealGbncd=00031R&srnID=PNO102001&_NAVI_CMD=&_NAVI_SRNID=&_SRCH_SRNID=PNO102001&_CUR_CMD=InitMulSrch.laf&_CUR_SRNID=PNO102001&_NEXT_CMD=RetrieveRealEstMulDetailList.laf&_NEXT_SRNID=PNO102002&_PRE_SRNID=&_LOGOUT_CHK=&_FORM_YN=Y'



response = requests.post(
    'https://www.courtauction.go.kr/RetrieveRealEstMulDetailList.laf',
    cookies=cookies,
    headers=headers,
    data=data,
)

#print(response.text)


soup = bs4.BeautifulSoup(response.text,"html.parser")


checkbox_value = soup.find('input',{'name':'chk'})['value']


items = []
item = {}
other = []
for court_info in soup.find_all('td'):
    tmp_list = court_info.get_text(separator='\n', strip=True).split('\n')

    if len(tmp_list) == 1 and tmp_list == ['']:
        continue

    if len(tmp_list) == 1:
        #print (tmp_list)
        continue
    elif len(tmp_list) == 2:
        #print (tmp_list)
        if tmp_list[0].find("법원") != -1 and item != {}:
            item['other'] = other
            other = []
            items.append(item)
            item = {}
            item['court'] = tmp_list[0]
            item['case_number'] = tmp_list[1]
        elif tmp_list[0] == '1':
            item['anony_num'] = tmp_list[0]
            item['property_type'] = tmp_list[1]
        else:
            other.append(tmp_list)
    elif len(tmp_list) == 3:
        print (tmp_list)
        #item['property_type'] = tmp_list[1]
    else:
        continue
        #print (tmp_list)



#    for tmp in tmp_list:
#        if tmp.find("법원") != -1 and item != {}:
#            items.append(item)
#            item = {}
#            item['court'] = tmp
#        elif tmp.find("타경") != -1:
#            item['case_number'] = tmp
#        elif tmp != '':
#            item['else'] = tmp
items.append(item)
item = []

for i in items:
    print(i)
