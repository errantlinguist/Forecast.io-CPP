#ifndef CURL_READING_HPP
#define CURL_READING_HPP

#include <curl/curl.h>

namespace curl
{

typedef size_t (WriteFunction)(char*, size_t, size_t, void*);

static constexpr long DEFAULT_TIMEOUT = 30L;

/**
 * @param[in] url The URL to call.
 * @param[in] pCallback The callback function To use for processing the response.
 * @param[out] pUserdata The data structure to output the read data to.
 * @param[in] timeout The response timeout in seconds.
 */
CURLcode read(const char* url, WriteFunction* pCallback, void* pUserdata, long timeout = DEFAULT_TIMEOUT);

/**
 * @param[in] url The URL to call.
 * @param[out] pOutput The stream to output the server response to.
 * @param[in] timeout The response timeout in seconds.
 * @return The cURL response code.
 */
CURLcode read(const char* url, FILE* pOutput, long timeout = DEFAULT_TIMEOUT);

}

#endif // CURL_READING_HPP
