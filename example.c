#include <stdio.h>
#include <curl/curl.h>



int main(int argc, char *argv[])
{
  CURLcode ret;
  CURL *hnd;
  struct curl_slist *headers;

  headers = NULL;
  headers = curl_slist_append(headers, "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7");
  headers = curl_slist_append(headers, "Accept-Language: en-US,en;q=0.9,ko;q=0.8");
  headers = curl_slist_append(headers, "Cache-Control: max-age=0");
  headers = curl_slist_append(headers, "Connection: keep-alive");
  headers = curl_slist_append(headers, "Content-Type: application/x-www-form-urlencoded");
  headers = curl_slist_append(headers, "Cookie: WMONID=gVHd10PYRiH; daepyoSidoCd=30; daepyoSiguCd=170; realVowel=35207_45207; realJiwonNm=%BC%AD%BF%EF%C1%DF%BE%D3%C1%F6%B9%E6%B9%FD%BF%F8; rd1Cd=30; rd2Cd=; JSESSIONID=Fca4qYc6g0dTHO03585e9ohy16eQWaCdnusGbgaAdcsUvm6AzKmMDrMHbFVlrD1Q.amV1c19kb21haW4vYWlzMQ==; locIdx=202301300014011; toMul=%B4%EB%C0%FC%C1%F6%B9%E6%B9%FD%BF%F8%2C20230130001401%2C1%2C20240807%2CB%5E");
  headers = curl_slist_append(headers, "Origin: https://www.courtauction.go.kr");
  headers = curl_slist_append(headers, "Sec-Fetch-Dest: frame");
  headers = curl_slist_append(headers, "Sec-Fetch-Mode: navigate");
  headers = curl_slist_append(headers, "Sec-Fetch-Site: same-origin");
  headers = curl_slist_append(headers, "Sec-Fetch-User: ?1");
  headers = curl_slist_append(headers, "Upgrade-Insecure-Requests: 1");
  headers = curl_slist_append(headers, "sec-ch-ua: \"Not)A;Brand\";v=\"99\", \"Google Chrome\";v=\"127\", \"Chromium\";v=\"127\"");
  headers = curl_slist_append(headers, "sec-ch-ua-mobile: ?0");
  headers = curl_slist_append(headers, "sec-ch-ua-platform: \"Linux\"");

  hnd = curl_easy_init();
  curl_easy_setopt(hnd, CURLOPT_BUFFERSIZE, 102400L);
  curl_easy_setopt(hnd, CURLOPT_URL, "https://www.courtauction.go.kr/RetrieveRealEstMulDetailList.laf");
  curl_easy_setopt(hnd, CURLOPT_NOPROGRESS, 1L);
  curl_easy_setopt(hnd, CURLOPT_POSTFIELDS, "bubwLocGubun=2&jiwonNm=%BC%AD%BF%EF%C1%DF%BE%D3%C1%F6%B9%E6%B9%FD%BF%F8&jpDeptCd=000000&daepyoSidoCd=30&daepyoSiguCd=170&daepyoDongCd=&notifyLoc=on&rd1Cd=30&rd2Cd=&realVowel=35207_45207&rd3Rd4Cd=&notifyRealRoad=on&saYear=2024&saSer=&ipchalGbncd=000331&termStartDt=2024.07.28&termEndDt=2024.08.11&lclsUtilCd=&mclsUtilCd=&sclsUtilCd=&gamEvalAmtGuganMin=&gamEvalAmtGuganMax=&notifyMinMgakPrcMin=&notifyMinMgakPrcMax=&areaGuganMin=&areaGuganMax=&yuchalCntGuganMin=&yuchalCntGuganMax=&notifyMinMgakPrcRateMin=&notifyMinMgakPrcRateMax=&srchJogKindcd=&mvRealGbncd=00031R&srnID=PNO102001&_NAVI_CMD=&_NAVI_SRNID=&_SRCH_SRNID=PNO102001&_CUR_CMD=InitMulSrch.laf&_CUR_SRNID=PNO102001&_NEXT_CMD=RetrieveRealEstMulDetailList.laf&_NEXT_SRNID=PNO102002&_PRE_SRNID=&_LOGOUT_CHK=&_FORM_YN=Y");
  curl_easy_setopt(hnd, CURLOPT_POSTFIELDSIZE_LARGE, (curl_off_t)772);
  curl_easy_setopt(hnd, CURLOPT_HTTPHEADER, headers);
  curl_easy_setopt(hnd, CURLOPT_REFERER, "https://www.courtauction.go.kr/InitMulSrch.laf");
  curl_easy_setopt(hnd, CURLOPT_USERAGENT, "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/127.0.0.0 Safari/537.36");
  curl_easy_setopt(hnd, CURLOPT_MAXREDIRS, 50L);
  curl_easy_setopt(hnd, CURLOPT_HTTP_VERSION, (long)CURL_HTTP_VERSION_2TLS);
  curl_easy_setopt(hnd, CURLOPT_FTP_SKIP_PASV_IP, 1L);
  curl_easy_setopt(hnd, CURLOPT_TCP_KEEPALIVE, 1L);

  ret = curl_easy_perform(hnd);

  curl_easy_cleanup(hnd);
  hnd = NULL;
  curl_slist_free_all(headers);
  headers = NULL;

  return (int)ret;
}
