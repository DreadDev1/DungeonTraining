// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MasterRoom.generated.h"

UCLASS()
class DUNGEONTRAINING_API AMasterRoom : public AActor
{
	GENERATED_BODY()

public:
	AMasterRoom();

protected:
	virtual void BeginPlay() override;

public:
	// Room Data Asset
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Room Generation")
	URoomData* RoomData;

	// Room Size Configuration (in tiles)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Room Generation|Size", meta = (ClampMin = "1"))
	int32 MinRoomSizeX = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Room Generation|Size", meta = (ClampMin = "1"))
	int32 MaxRoomSizeX = 8;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Room Generation|Size", meta = (ClampMin = "1"))
	int32 MinRoomSizeY = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Room Generation|Size", meta = (ClampMin = "1"))
	int32 MaxRoomSizeY = 8;

	// Debug options
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Room Generation|Debug")
	bool bShowDebugInfo = false;
};
