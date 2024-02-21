package com.wavem.persistence;

import java.util.List;
import java.util.Map;

import org.apache.ibatis.annotations.Mapper;

import com.wavem.vo.DistanceDataVO;

@Mapper
public interface DistanceDataMapper {

	public List<DistanceDataVO> getDistanceData(Map<String, Object> map);

	public boolean insertDistanceData(Map<String, Object> map);
	
	public boolean insertDistanceData(List<DistanceDataVO> list);

}
