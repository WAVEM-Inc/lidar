package com.wavem.service;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.wavem.persistence.DistanceDataMapper;
import com.wavem.vo.DistanceDataVO;


@Service
public class DistanceDataServiceImpl implements DistanceDataService {
	
	@Autowired
	private DistanceDataMapper distanceDataMapper;
	
	@Override
	public List<DistanceDataVO> getDistanceData(Map<String, Object> map) {
		
		List<DistanceDataVO> list = null; 
				
		try {
	
			list = distanceDataMapper.getDistanceData(map);
		}catch(Exception e) {
			e.printStackTrace();
		}
		return list;
	}
/*
	@Override
	public boolean insertDistanceData(Map<String, Object> map) {
		
		String detectionTime = (String) map.get("detectionTime");
        Integer rangeIndex = (Integer) map.get("rangeIndex");
    	Float rangeData = (Float) map.get("rangeData");
    	Integer channel = (Integer) map.get("channel");
    	Integer detectionValue = (Integer) map.get("detectionValue");
    	   
    	try {
	    	
    		if ( !distanceDataMapper.insertDIstanceData(map) )
    			return false;
	    	
    	}catch(Exception e) {
    		e.printStackTrace();
    		return false;
    	}
    	
		return true;
	}
	*/	
	@Override
	public boolean insertDistanceData(List<DistanceDataVO> list) {
    	
    	/*Map<String, Object> map = new HashMap<String, Object>();
    	
    	map.put("detectionTime", data.getDetectionTime());
    	map.put("rangeIndex", data.getRangeIndex());
    	map.put("rangeData", data.getRangeData());
    	map.put("channel", data.getChannel());
    	map.put("detectionValue", data.getDetectionValue());
    	*/
    	try {
	    	
    		  Map<String, Object> map = new HashMap<String, Object>();
              map.put("distanceData", list);
              
    		if ( !distanceDataMapper.insertDistanceData(map) )
    			return false;
	    	
    	}catch(Exception e) {
    		e.printStackTrace();
    		return false;
    	}
    	
		return true;
	}
	
}
