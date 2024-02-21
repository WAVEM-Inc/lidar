package com.wavem.controller;


import java.io.BufferedReader;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.net.URLDecoder;
import java.util.Enumeration;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.servlet.http.HttpServletRequest;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
/*import org.json.JSONObject;
import org.json.simple.JSONArray;
import org.json.simple.parser.JSONParser;
import org.json.simple.parser.ParseException;*/
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import com.google.gson.Gson;
import com.wavem.LidarReceiverApplication;
import com.wavem.service.DistanceDataService;
import com.wavem.service.MulticastEchoServer;
import com.wavem.vo.DistanceDataVO;


@RestController
@RequestMapping("lidar")
public class distanceDataController {
		
	@Autowired
	private DistanceDataService distanceDataService;
	 
	@Autowired
	public MulticastEchoServer server;
	
	private static final Logger logger = LogManager.getLogger(distanceDataController.class);

	@GetMapping(value = "/distanceDataHis")
	private String getDistanceData (@RequestParam String detectionTime){
		
		 String jsonString = null;
	 
	    try {
	    	
	    	Map<String, Object> map = new  HashMap<String, Object>();
	    	map.put("detectionTime", detectionTime);
	    	List<DistanceDataVO>list = null;
	    	list = distanceDataService.getDistanceData(map);
	    	
	    	if ( list == null )
	    		return null;
	    	
	    	Gson gson = new Gson();
		    jsonString = gson.toJson(list);
		    System.out.println(jsonString);
			
	    }catch(Exception e) {
	    	logger.info("Error reading JSON string: " + e.toString());
	    }
	    
	    return jsonString.toString();
	}
	
	@GetMapping(value = "/udpend")
	private void endUDP (){
		
		System.out.println("End UDP");
		
		server.interrupt();
		
	}
}
