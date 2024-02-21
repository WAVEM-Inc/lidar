package com.wavem.vo;

import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

@Getter
@Setter
@ToString
public class DistanceDataVO {

	String detectionTime;
	int rangeIndex;
	float rangeData;
	String channel; 
	int detectionValue;
	public DistanceDataVO(String detectionTime, int rangeIndex,float rangeData, String channel, int detectionValue) {
		super();
		this.detectionTime = detectionTime;
		this.rangeIndex = rangeIndex;
		this.rangeData = rangeData;
		this.channel = channel;
		this.detectionValue = detectionValue;
	}
	
}
