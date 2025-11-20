// Fill out your copyright notice in the Description page of Project Settings.


#include "Rooms/MasterRoom.h"

#include "Components/InstancedStaticMeshComponent.h"


// Sets default values
AMasterRoom::AMasterRoom()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	// Create root component
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

// Called when the game starts or when spawned
void AMasterRoom::BeginPlay()
{
	Super::BeginPlay();
	
}