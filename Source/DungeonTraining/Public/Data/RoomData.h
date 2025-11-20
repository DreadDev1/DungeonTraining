// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "RoomData.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONTRAINING_API URoomData : public UDataAsset
{
	GENERATED_BODY()
	
public:
	// Floor Mesh
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Room Meshes|Floor")
	UStaticMesh* FloorMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Room Meshes|Floor")
	FVector FloorMeshSize = FVector(200.0f, 200.0f, 100.0f);

	// Wall Meshes (3-piece system: Bottom, Middle, Top)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Room Meshes|Wall")
	UStaticMesh* WallMeshBottom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Room Meshes|Wall")
	FVector WallBottomSize = FVector(400.0f, 100.0f, 100.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Room Meshes|Wall")
	UStaticMesh* WallMeshMiddle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Room Meshes|Wall")
	FVector WallMiddleSize = FVector(400.0f, 100.0f, 200.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Room Meshes|Wall")
	UStaticMesh* WallMeshTop;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Room Meshes|Wall")
	FVector WallTopSize = FVector(400.0f, 100.0f, 100.0f);

	// Doorway Mesh
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Room Meshes|Doorway")
	UStaticMesh* DoorwayMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Room Meshes|Doorway")
	FVector DoorwayMeshSize = FVector(400.0f, 100.0f, 300.0f);

	// Wall positioning offset (adjust if walls don't align perfectly)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Room Meshes|Wall")
	float WallOffsetAdjustment = 0.0f;

	// Wall rotation adjustment (in degrees, added to base rotation)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Room Meshes|Wall")
	float WallRotationAdjustment = 0.0f;
};
