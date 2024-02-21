package com.wavem.vo;

import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

public class DistanceDataVO {

	String detectionTime;
	int rangeIndex;
	float rangeData;
	String channel; 
	int detectionValue;

	
	
	public String getDetectionTime() {
		return detectionTime;
	}

	public void setDetectionTime(String detectionTime) {
		this.detectionTime = detectionTime;
	}

	public int getRangeIndex() {
		return rangeIndex;
	}

	public void setRangeIndex(int rangeIndex) {
		this.rangeIndex = rangeIndex;
	}

	public float getRangeData() {
		return rangeData;
	}

	public void setRangeData(float rangeData) {
		this.rangeData = rangeData;
	}

	public String getChannel() {
		return channel;
	}

	public void setChannel(String channel) {
		this.channel = channel;
	}

	public int getDetectionValue() {
		return detectionValue;
	}

	public void setDetectionValue(int detectionValue) {
		this.detectionValue = detectionValue;
	}

	public DistanceDataVO(String detectionTime, int rangeIndex,float rangeData, String channel, int detectionValue) {
		super();
		this.detectionTime = detectionTime;
		this.rangeIndex = rangeIndex;
		this.rangeData = rangeData;
		this.channel = channel;
		this.detectionValue = detectionValue;
	}
	
	public DistanceDataVO() {
		super();
	}
	
}
