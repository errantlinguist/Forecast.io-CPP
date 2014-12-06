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
		 * The callback function To use for processing server responses (see the cURL option "CURLOPT_WRITEFUNCTION").
		**/
		typedef size_t (WriteFunction)(char*, size_t, size_t, void*);

		static constexpr long DEFAULT_TIMEOUT = 30L;

		/** Default constructor */
		CallbackClient(char * errorBuffer);
		/** Default destructor */
		virtual ~CallbackClient();

		/**
		 * @param[in] url The URL to call.
		 * @param[in] pCallback The callback function To use for processing the response (see the cURL option "CURLOPT_WRITEFUNCTION").
		 * @param[out] pUserdata The data structure to output the read data to.
		 * @param[in] timeout The response timeout in seconds.
		 */
		CURLcode read(const char* url, WriteFunction* pCallback, void* pUserdata, long timeout = DEFAULT_TIMEOUT);

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
		CURL* curl;

		/**
		 * The buffer to which cURL error messages are written (see <a href="http://curl.haxx.se/libcurl/c/CURLOPT_ERRORBUFFER.html">CURLOPT_ERRORBUFFER</a>).
		**/
		char* errorBuffer;

		CURLcode setupHandle(CURL*& curl);

};

}

#endif // WRITEFUNCTIONCLIENT_HPP
