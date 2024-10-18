// Story Graph by JDNLY. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Engine/Blueprint.h"
#include "StoryGraphBlueprint.generated.h"

//class UStoryGraph;
class UEdGraph_StoryGraph;

/**
 * 
 */

UCLASS()
class STORYGRAPHRUNTIME_API UStoryGraphBlueprint : public UBlueprint
{
	GENERATED_BODY()

	//UPROPERTY()
	//UStoryGraph* StoryGraph;

	UPROPERTY()
	TArray<UEdGraph_StoryGraph*> Graphs;

	UEdGraph_StoryGraph* FindGraph(UObject* GraphOwner);

	void AddGraph(UEdGraph_StoryGraph* Graph) { Graphs.Add(Graph); }

	void RemoveGraph(UEdGraph_StoryGraph* Graph) { Graphs.RemoveSingle(Graph); }
};

UCLASS()
class UExecutionTree : public UObject
{
	GENERATED_BODY()
public:
	//UPROPERTY(SaveGame)
	//class UStoryGraphQuest* MainQuest;

	//UPROPERTY(SaveGame)
	//TArray<class UStoryVerticalNodeBase*> PredActiveNodesBuffer;

public:
	void Refresh();

};
/*
UCLASS()
class UStoryGraph : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY()
	int32 CompilationCounter;

	UPROPERTY(SaveGame)
	int32 LoadedCompilationCounter;

	//UPROPERTY()
	//TArray<class UStoryGraphObject*> GarphObjects;

	//UPROPERTY()
	//TArray<class UCustomNodeBase*> GarphNods;

	UPROPERTY()
	TArray<UExecutionTree*> ExecutionTrees;


	bool QuestStateWasChange; // If quest state was change during refresh execution tree, tree must be refresh again.

	
	//#if WITH_EDITORONLY_DATA
	//FAssetEditor_StoryGraph* pAssetEditor;

	//UPROPERTY()
	//EStoryGraphState StoryGraphState;
//#endif //WITH_EDITORONLY_DATA

	AActor* OwnedActor = nullptr;

private:

	bool OldSaveFile;
	
public:
	
	//virtual void GetInternallySaveObjects(TArray<UObject*>& Objects, int WantedObjectsNum) override;// ISaveObject_StoryGraph interface

	void CreateExecutionTrees();

	void RefreshExecutionTrees(bool NeedRefreshQuestsPhase = true);

	void RefreshQuestsPhase();

	void RefreshRadarTargets();

private:
	/** Gets all the Graph Objects of a given type */
	//template<class MinRequiredType>
	//void GetGraphObjectsOfClass(TArray<MinRequiredType*>& OutObjects) const;
	
//};
