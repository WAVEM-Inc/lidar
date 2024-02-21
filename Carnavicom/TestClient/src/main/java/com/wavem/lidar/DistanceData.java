package com.wavem.lidar;

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import org.apache.http.Header;
import org.apache.http.message.BasicHeader;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.core.type.TypeReference;
import com.fasterxml.jackson.databind.JsonMappingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.wavem.util.HTTPClient;
import com.wavem.vo.DistanceDataVO;


public class DistanceData {
	
	private static final Logger logger = LoggerFactory.getLogger(DistanceData.class);
	
	
    private HTTPClient client = new HTTPClient();
	
	private String protocol = "http";
	private String endpoint = "127.0.0.1:8089";
	private String URI = "/lidar/distanceDataHis";
	
	public DistanceData(String protocol, String endpoint) {
		super();
		this.protocol = protocol;
		this.endpoint = endpoint;
	}


	public List<DistanceDataVO> getDistanceData(String detectedTime){ 
		
		ObjectMapper mapper = new ObjectMapper();
		
		String url = protocol +"://"+ endpoint + URI + "?detectionTime="+ detectedTime;		

		SimpleDateFormat formatter= new SimpleDateFormat("yyyy-MM-dd 'at' HH:mm:ss z");
		Date date = new Date(System.currentTimeMillis());
		String currentDate = formatter.format(date);
	
		logger.info("[%s]request distance data",currentDate);
		
		Header[] headers = new Header[] {
				new BasicHeader("Content-Type", "application/json")				
		};
		
		byte[] result 	= this.client.get(url, headers);
		
		if(result == null || result.length == 0) {
			logger.info("result is empty.");
			return null;
		}
				
		String resultString = new String(result);
		
		List<DistanceDataVO> list = null;
		try {
			
			
			list = mapper.readValue(resultString, new TypeReference<ArrayList<DistanceDataVO>>(){});
		} catch (JsonMappingException e) {
			e.printStackTrace();
		} catch (JsonProcessingException e) {
			e.printStackTrace();
		}		
		return list;		
	}
	
}
