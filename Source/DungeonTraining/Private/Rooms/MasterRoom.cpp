// Fill out your copyright notice in the Description page of Project Settings.


#include "Rooms/MasterRoom.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Data/RoomData.h"

AMasterRoom::AMasterRoom()
{
	PrimaryActorTick.bCanEverTick = false;
	
	USceneComponent* Root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = Root;

	// Create Instanced Static Mesh Components
	FloorInstances = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("FloorInstances"));
	FloorInstances->SetupAttachment(RootComponent);

	WallBottomInstances = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("WallBottomInstances"));
	WallBottomInstances->SetupAttachment(RootComponent);

	WallMiddleInstances = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("WallMiddleInstances"));
	WallMiddleInstances->SetupAttachment(RootComponent);

	WallTopInstances = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("WallTopInstances"));
	WallTopInstances->SetupAttachment(RootComponent);
}

void AMasterRoom::BeginPlay()
{
	Super::BeginPlay();
	
	GenerateRoom();
}

void AMasterRoom::GenerateRoom()
{
	if (bShowDebugInfo)
	{ UE_LOG(LogTemp, Warning, TEXT("=== MasterRoom: GenerateRoom Started ==="));}

	if (!RoomData)
	{
		UE_LOG(LogTemp, Error, TEXT("MasterRoom: No RoomData assigned!"));
		return;
	}

	if (!RoomData->FloorMesh)
	{
		UE_LOG(LogTemp, Error, TEXT("MasterRoom: No FloorMesh assigned in RoomData!"));
		return;
	}

	// Set the static mesh for floor instances
	FloorInstances->SetStaticMesh(RoomData->FloorMesh);

	// Randomly determine room dimensions
	int32 RoomSizeX = FMath::RandRange(MinRoomSizeX, MaxRoomSizeX);
	int32 RoomSizeY = FMath::RandRange(MinRoomSizeY, MaxRoomSizeY);

	UE_LOG(LogTemp, Log, TEXT("MasterRoom: Generating room of size %dx%d"), RoomSizeX, RoomSizeY);

	if (bShowDebugInfo)
	{
		UE_LOG(LogTemp, Warning, TEXT("Floor Mesh Size: X=%f, Y=%f, Z=%f"), 
			RoomData->FloorMeshSize.X, RoomData->FloorMeshSize.Y, RoomData->FloorMeshSize.Z);
	}

	// Generate floor
	GenerateFloor(RoomSizeX, RoomSizeY);

	// Generate walls
	GenerateWalls(RoomSizeX, RoomSizeY);

	if (bShowDebugInfo)
	{
		UE_LOG(LogTemp, Warning, TEXT("=== MasterRoom: GenerateRoom Completed ==="));
	}
}

void AMasterRoom::GenerateFloor(int32 RoomSizeX, int32 RoomSizeY)
{
	for (int32 Y = 0; Y < RoomSizeY; Y++)
	{
		for (int32 X = 0; X < RoomSizeX; X++)
		{
			FVector SpawnLocation = GetFloorTileLocation(X, Y);
			FTransform InstanceTransform(FRotator::ZeroRotator, SpawnLocation, FVector(1.0f));
			
			FloorInstances->AddInstance(InstanceTransform);
		}
	}

	if (bShowDebugInfo)
	{
		UE_LOG(LogTemp, Log, TEXT("MasterRoom: Generated %d floor instances"), FloorInstances->GetInstanceCount());
	}
}

FVector AMasterRoom::GetFloorTileLocation(int32 X, int32 Y) const
{
	if (!RoomData)
	{
		return GetActorLocation();
	}

	// Calculate position based on floor mesh size
	FVector TileOffset;
	TileOffset.X = X * RoomData->FloorMeshSize.X;
	TileOffset.Y = Y * RoomData->FloorMeshSize.Y;
	TileOffset.Z = 0.0f;

	return GetActorLocation() + TileOffset;
}

void AMasterRoom::GenerateWalls(int32 RoomSizeX, int32 RoomSizeY)
{
}

// FVector AMasterRoom::GetWallLocation(int32 X, int32 Y, bool bIsNorthSouth, bool bIsEastWest) const
// {
// }
//
// FRotator AMasterRoom::GetWallRotation(bool bIsNorthSouth) const
// {
// }


