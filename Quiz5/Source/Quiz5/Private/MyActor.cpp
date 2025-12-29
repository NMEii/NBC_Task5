// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include  "Engine/Engine.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	turnCount = 0;
	moveCount = 0;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(FVector(0, 50, 0));
	startLocation = GetActorLocation();
	
	for (int i = 0; i < 10; i++)
	{
		RandomEvent();
		GEngine->AddOnScreenDebugMessage(
			-1,
			10.0f,
			FColor::Blue,
			FString::Printf(TEXT("Total Count : %d"), i+1)
		);

	}


	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(	// 회전 횟수 출력
			-1,
			10.0f,
			FColor::Blue,
			FString::Printf(TEXT("Turn Count : %d"), turnCount)
		);

		GEngine->AddOnScreenDebugMessage(	// 이동 횟수 출력
			-1,
			10.0f,
			FColor::Blue,
			FString::Printf(TEXT("Move Count : %d"), moveCount)
		);

		GEngine->AddOnScreenDebugMessage(	// 시작 지점에서 마지막 위치까지의 거리
			-1,
			10.0f,
			FColor::Red,
			*(actorLocation - startLocation).ToString()
		);
	}

}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActor::Turn()
{
	SetActorRotation(FRotator(100.f, 100.f, 100.f));
	actorLocation = GetActorLocation();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			10.0f,
			FColor::Yellow,
			*actorLocation.ToString()
		);
	}

}

void AMyActor::Move()
{
	AddActorLocalOffset(FVector(50.f, 0.f, 0.f));
	actorLocation = GetActorLocation();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			10.0f,
			FColor::Green,
			*actorLocation.ToString()
		);
	}
}

void AMyActor::RandomEvent()
{
	int i_random = FMath::RandRange(0, 100);

	if (i_random > 50)
	{
		moveCount++;
		Move();
	}
	else
	{
		turnCount++;
		Turn();
	}
}

