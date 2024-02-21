package com.wavem.util;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;

import org.apache.http.Header;
import org.apache.http.HttpEntity;
import org.apache.http.HttpResponse;
import org.apache.http.client.config.RequestConfig;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.entity.StringEntity;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.impl.client.HttpClientBuilder;
import org.apache.http.impl.client.HttpClients;
import org.apache.http.util.EntityUtils;
import org.json.simple.JSONObject;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class HTTPClient {
	
	private final static Logger logger = LoggerFactory.getLogger(HTTPClient.class);
	private final static int	DEFAULT_TIMEOUT	= 10 * 1000;	/* 10 sec. */
	
	private int requestTimeOut 	= DEFAULT_TIMEOUT;
	private int socketTimeOut	= DEFAULT_TIMEOUT;
	private int	connTimeOut		= DEFAULT_TIMEOUT;
	
	public HTTPClient() {
		this.requestTimeOut = DEFAULT_TIMEOUT;
		this.socketTimeOut 	= DEFAULT_TIMEOUT;
		this.connTimeOut 	= DEFAULT_TIMEOUT;
	}
	public HTTPClient(int requestTimeout, int socketTimeout, int connTimeout) {
		this.requestTimeOut = requestTimeout;
		this.socketTimeOut 	= socketTimeout;
		this.connTimeOut 	= connTimeout;
	}
	public HTTPClient(JSONObject timeout) {
		Long tmp = (timeout == null || (Long)timeout.get("request") == null) ? DEFAULT_TIMEOUT : (Long)timeout.get("request");
		this.requestTimeOut = tmp.intValue();
		
		tmp = (timeout == null || (Long)timeout.get("socket") == null) ? DEFAULT_TIMEOUT : (Long)timeout.get("socket");;
		this.socketTimeOut 	= tmp.intValue();
		
		tmp = (timeout == null || (Long)timeout.get("connection") == null) ? DEFAULT_TIMEOUT : (Long)timeout.get("connection");
		this.connTimeOut 	= tmp.intValue();
	}
	/**
	 * get HTTP response via HTTP get method
	 * @param url
	 * @param headers
	 * @return response entity
	 */
	public byte[] get(String url, Header[] headers) {
		/* request */
		CloseableHttpClient httpClient 	= null; 
		HttpGet 			req 		= null;
		
		/* response */
		HttpResponse 		res			= null; 
		HttpEntity 			entity 		= null;
		byte[]				result		= null;
		
		RequestConfig config = RequestConfig.custom()
				  .setConnectTimeout(this.connTimeOut)
				  .setConnectionRequestTimeout(this.requestTimeOut)
				  .setSocketTimeout(this.socketTimeOut).build();
		
		httpClient 	= HttpClientBuilder.create().setDefaultRequestConfig(config).build();
		req 		= new HttpGet(url);
		/* appointed headers */
		req.setHeaders(headers);
		
		try  {
			res    = httpClient.execute(req);
			entity = res.getEntity();
			result = this.convert(entity.getContent());
			EntityUtils.consume(entity);
		}catch(IOException e) {
			logger.error(e.getMessage());
			for (StackTraceElement element : e.getStackTrace()) {
				logger.error(element.toString());
			}
			return null;
		} finally {
			try {
				httpClient.close();
			} catch (IOException e) {
				logger.error(e.getMessage());
				for (StackTraceElement element : e.getStackTrace()) {
					logger.error(element.toString());
				}
			}
		}
		if(res.getStatusLine().getStatusCode() != 200) {
			return null;
		}
		return result;
	}
	public byte[] post(String url, Header[] headers, JSONObject body) {
		
		CloseableHttpClient httpClient 	= HttpClients.createDefault();
		HttpPost 			httpPost 	= new HttpPost(url);
		HttpResponse 		response 	= null;
		HttpEntity 			entity 		= new StringEntity(body.toString(), "UTF-8");
		byte[]				result		= null;
		
		try {
			httpPost.setHeaders(headers);
			httpPost.setEntity(entity);
			
			response 	= httpClient.execute(httpPost);
		//	response.getFirstHeader(name)
			entity 		= response.getEntity();
			Integer status = response.getStatusLine().getStatusCode();
			body.put("httpstatus", status);
			result 		= this.convert(entity.getContent());
			EntityUtils.consume(entity);
		} catch(Exception e) {
			logger.error(e.getMessage());
			for (StackTraceElement element : e.getStackTrace()) {
				logger.error(element.toString());
			}
			return null;
		} finally {
			try {
				httpClient.close();
			} catch (IOException e) {
				logger.error(e.getMessage());
				for (StackTraceElement element : e.getStackTrace()) {
					logger.error(element.toString());
				}
			}
		}
		return result;
	}
	/**
	 * read content via inputstream
	 * @param is
	 * @return content (byte array)
	 */
	private byte[] convert(InputStream is) {
		ByteArrayOutputStream 	baos = new ByteArrayOutputStream();
		int 	read 	= -1;
		byte[]  buffer	= new byte[1024];

		try {
			while ((read = is.read(buffer)) != -1) {
				baos.write(buffer, 0, read);
			}
			baos.flush();
		} catch (IOException e) {
			logger.error(e.getMessage());
			for (StackTraceElement element : e.getStackTrace()) {
				logger.error(element.toString());
			}
		}finally {
			try {
				if(baos != null) {
					baos.close();
				}
			} catch (IOException e) {
				logger.error(e.getMessage());
				for (StackTraceElement element : e.getStackTrace()) {
					logger.error(element.toString());
				}
			}
		}
		return baos.toByteArray();
	}
}