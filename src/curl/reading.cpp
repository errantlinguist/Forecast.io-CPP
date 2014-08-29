#include "curl/reading.hpp"

// See <http://www.cplusplus.com/forum/unices/45878/#msg249287>

namespace curl
{

CURLcode read(const char* url, WriteFunction* pCallback, void* pUserdata,
		long timeout)
{
	CURLcode result(CURLE_FAILED_INIT);
	CURL* curl = curl_easy_init();

	if (curl)
	{
		if (CURLE_OK
				== (result = curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L))
				&& CURLE_OK
						== (result = curl_easy_setopt(curl,
								CURLOPT_FOLLOWLOCATION, 1L))
				&& CURLE_OK
						== (result = curl_easy_setopt(curl,
								CURLOPT_WRITEFUNCTION, pCallback))
				&& CURLE_OK
						== (result = curl_easy_setopt(curl, CURLOPT_WRITEDATA,
								pUserdata)) && CURLE_OK == (result =
						curl_easy_setopt(curl, CURLOPT_TIMEOUT, timeout))
				&& CURLE_OK
						== (result = curl_easy_setopt(curl, CURLOPT_URL, url)))
		{
			result = curl_easy_perform(curl);
		}

		curl_easy_cleanup(curl);
	}
	return result;
}

CURLcode read(const char* url, FILE* pOutput, long timeout)
{
	CURLcode result(CURLE_FAILED_INIT);
	CURL* curl = curl_easy_init();

	if (curl)
	{
		if (CURLE_OK
				== (result = curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L))
				&& CURLE_OK
						== (result = curl_easy_setopt(curl,
								CURLOPT_FOLLOWLOCATION, 1L))
				&& CURLE_OK
						== (result = curl_easy_setopt(curl, CURLOPT_WRITEDATA,
								pOutput)) && CURLE_OK == (result =
						curl_easy_setopt(curl, CURLOPT_TIMEOUT, timeout))
				&& CURLE_OK
						== (result = curl_easy_setopt(curl, CURLOPT_URL, url)))
		{
			result = curl_easy_perform(curl);
		}

		curl_easy_cleanup(curl);
	}
	return result;
}

}

