#include "curl/CallbackClient.hpp"

// See <http://www.cplusplus.com/forum/unices/45878/#msg249287>

namespace curl
{

CallbackClient::CallbackClient(char* const& pErrorBuffer) : pCurlHandle(curl_easy_init()), pErrorBuffer(pErrorBuffer), pHeaders(NULL)
{
	if (pCurlHandle)
	{
		CURLcode setupResult = setupHandle(pCurlHandle);
		if (CURLE_OK != setupResult)
		{
			throw setupResult;
		}
	} else
	{
		throw CURLE_FAILED_INIT;
	}
}

CallbackClient::~CallbackClient()
{
	// Clean up resources for cURL library
	curl_easy_cleanup(pCurlHandle);
	if (pHeaders != NULL)
	{
		curl_slist_free_all(pHeaders);
	}
}

bool CallbackClient::addHeader(const char* const& pHeader)
{
	bool result(false);

	curl_slist* pNewHeaders = curl_slist_append(pHeaders, pHeader);
	if (pNewHeaders != NULL)
	{
		pHeaders = pNewHeaders;
		result = true;
	}

	return result;
}

CURLcode CallbackClient::getInfo(CURLINFO info, void* pInfoData) const
{
	return curl_easy_getinfo(pCurlHandle, info, pInfoData);
}

CURLcode CallbackClient::read(const char* url, WriteFunction* pCallback, void* pUserData,
		long timeout)
{
	CURLcode result(CURLE_FAILED_INIT);

	if (
			CURLE_OK == (result = curl_easy_setopt(pCurlHandle, CURLOPT_WRITEFUNCTION, pCallback))
			&& CURLE_OK == (result = curl_easy_setopt(pCurlHandle, CURLOPT_WRITEDATA, pUserData))
			&& CURLE_OK == (result = curl_easy_setopt(pCurlHandle, CURLOPT_TIMEOUT, timeout))
			&& CURLE_OK == (result = curl_easy_setopt(pCurlHandle, CURLOPT_URL, url)))
	{
		if (pHeaders != NULL)
		{
			result = curl_easy_setopt(pCurlHandle, CURLOPT_HTTPHEADER, pHeaders);
			if (CURLE_OK == result)
			{
				result = curl_easy_perform(pCurlHandle);
			}
		}
	}

	return result;
}

CURLcode CallbackClient::setupHandle(CURL*& pCurlHandle)
{
	CURLcode result(curl_easy_setopt(pCurlHandle, CURLOPT_ERRORBUFFER, pErrorBuffer));
	if (CURLE_OK == result)
	{
		result = curl_easy_setopt(pCurlHandle, CURLOPT_NOPROGRESS, 1L);
		if (CURLE_OK == result)
		{
			CURLE_OK == (result = curl_easy_setopt(pCurlHandle, CURLOPT_FOLLOWLOCATION, 1L));
		}
	}

	return result;
}

//CURLcode CallbackClient::read(const char* url, FILE* pOutput, long timeout)
//{
//	CURLcode result(CURLE_FAILED_INIT);
//
//	if (CURLE_OK
//			== (result = curl_easy_setopt(pCurlHandle, CURLOPT_NOPROGRESS, 1L))
//			&& CURLE_OK
//					== (result = curl_easy_setopt(pCurlHandle,
//							CURLOPT_FOLLOWLOCATION, 1L))
//			&& CURLE_OK
//					== (result = curl_easy_setopt(pCurlHandle, CURLOPT_WRITEDATA,
//							pOutput)) && CURLE_OK == (result =
//					curl_easy_setopt(pCurlHandle, CURLOPT_TIMEOUT, timeout))
//			&& CURLE_OK
//					== (result = curl_easy_setopt(pCurlHandle, CURLOPT_URL, url)))
//	{
//		result = curl_easy_perform(pCurlHandle);
//	}
//
//	return result;
//}

}
