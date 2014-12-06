#ifndef WRITEFUNCTIONCLIENT_HPP
#define WRITEFUNCTIONCLIENT_HPP

#include <curl/curl.h>

namespace curl
{

/**
* A class for setting up a handler for making calls to the cURL library and then cleaning up the associated resources on destruction.
* <b>NOTE:</b> <a href="http://curl.haxx.se/libcurl/c/curl_global_init.html">curl_global_init</a> should have already been called before creating an instance of this class.
*/
class CallbackClient
{
	public:

		/**
		 * The callback function To use for processing server responses (see the cURL option "<a href="http://curl.haxx.se/libcurl/c/CURLOPT_WRITEFUNCTION.html">CURLOPT_WRITEFUNCTION</a>").
		**/
		typedef size_t (WriteFunction)(char*, size_t, size_t, void*);

		static constexpr long DEFAULT_TIMEOUT = 30L;

		/**
		 * @param[in] pErrorBuffer The character array to write any error messages to.
		 * @throws CURLcode If there was an error while initialising/setting up the cURL handle.
		**/
		CallbackClient(char* const& pErrorBuffer);
		/** Default destructor */
		virtual ~CallbackClient();

		/**
		 * @param[in] pHeader The header string to add.
		 * @return true iff the string was successfully added.
		**/
		bool addHeader(const char* const& pHeader);

		/**
		* Gets information about the last cURL action.
		* @param[in] info The type of information to get.
		* @param[out] pInfoData A pointer to a data structure for storing the information returned. This must be a pointer to a long, char array, a curl_slist or a double (see the <a href="http://curl.haxx.se/libcurl/c/curl_easy_getinfo.html#DESCRIPTION">documentation for curl_easy_getinfo</a>).
		* @return The cURL response code. If this does not equal CURLE_OK, the information should not be trusted.
		**/
		CURLcode getInfo(CURLINFO info, void* pInfoData) const;

		/**
		 * @param[in] url The URL to call.
		 * @param[in] pCallback The callback function To use for processing the response (see the cURL option "<a href="http://curl.haxx.se/libcurl/c/CURLOPT_WRITEFUNCTION.html">CURLOPT_WRITEFUNCTION</a>").
		 * @param[out] pUserData The data structure to output the read data to.
		 * @param[in] timeout The response timeout in seconds.
		 */
		CURLcode read(const char* url, WriteFunction* pCallback, void* pUserData, long timeout = DEFAULT_TIMEOUT);

//		/**
//		 * @param[in] url The URL to call.
//		 * @param[out] pOutput The stream to output the server response to.
//		 * @param[in] timeout The response timeout in seconds.
//		 * @return The cURL response code.
//		 */
//		CURLcode read(const char* url, FILE* pOutput, long timeout = DEFAULT_TIMEOUT);

	private:

		/**
		 * The easy handle object for making calls using the cURL library (see <a href="http://curl.haxx.se/libcurl/c/curl_easy_init.html">the cURL API</a>).
		**/
		CURL* pCurlHandle;

		/**
		 * The buffer to which cURL error messages are written (see <a href="http://curl.haxx.se/libcurl/c/CURLOPT_ERRORBUFFER.html">CURLOPT_ERRORBUFFER</a>).
		**/
		char* const& pErrorBuffer;

		/**
		* A list of headers to add to the next request sent.
		*/
		curl_slist* pHeaders;

		/**
		 * @param[in] pCurlHandle The cURL easy handle instance to set up.
		 * @return The cURL response code.
		**/
		CURLcode setupHandle(CURL*& pCurlHandle);

};

}

#endif // WRITEFUNCTIONCLIENT_HPP
