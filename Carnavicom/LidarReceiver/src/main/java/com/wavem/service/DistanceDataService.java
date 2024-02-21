package com.wavem.service;

import java.util.List;
import java.util.Map;

import org.springframework.stereotype.Service;

import com.wavem.vo.DistanceDataVO;

@Service
public interface DistanceDataService {

	
	List<DistanceDataVO> getDistanceData(Map<String, Object> map);

	//boolean insertDistanceData(Map<String, Object> map);

	boolean insertDistanceData(List<DistanceDataVO> list);
}
